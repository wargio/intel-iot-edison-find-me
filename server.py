#!/usr/bin/python

import threading, time
import SimpleHTTPServer
import SocketServer
import signal
import logging
import cgi
import subprocess
import os
import sys


if (not os.path.isfile("./button")) or (not os.path.isfile("./server.sh")):
    print("you need to build the deps before running this. run 'make'")
    sys.exit(0)

def getCoord(s):
    subprocess.Popen("./server.sh")
    f = open('./coord.txt', 'r')
    s.wfile.write(f.read())
    f.close()

if len(sys.argv) > 2:
    PORT = int(sys.argv[2])
    I = sys.argv[1]
elif len(sys.argv) > 1:
    PORT = int(sys.argv[1])
    I = ""
else:
    PORT = 8000
    I = ""

subprocess.Popen("./server.sh")

class Worker(threading.Thread):
  def __init__(self):
    threading.Thread.__init__(self)
    self.kill_received = False

  def run(self):
      print("thread is running")
      while not self.kill_received:
          self.do_something()

  def do_something(self):
      p = subprocess.Popen(['./button'], stdout=subprocess.PIPE,stderr=subprocess.PIPE)
      out, err = p.communicate()
      if out == "1\n":
         subprocess.Popen("./server.sh")
         f = open('./coord.txt', 'r')
         print("updating coords!" + f.read())
         f.close()

class ServerHandler(SimpleHTTPServer.SimpleHTTPRequestHandler):

    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
        getCoord(self)

Handler = ServerHandler

httpd = SocketServer.TCPServer(("", PORT), Handler)
t = Worker()
def signal_handler(signal, frame):
        print('Ending...')
        httpd.server_close()
        t.kill_received = True
        sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)

print "Python http server version 0.1 (Edison)"
print "Serving at: http://%(interface)s:%(port)s" % dict(interface=I or "localhost", port=PORT)
t.start()
try:
    httpd.serve_forever()
except KeyboardInterrupt:
    t.kill_received = True
    pass
httpd.server_close()
t.join()

