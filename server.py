from bottle import route, run, template, post, request
import subprocess

form = open('interface.html').read()

@route('/')
def index():
    return form 

@post('/')
def action():
    color = request.forms.get('color') or 'r'
    speed = request.forms.get('speed') or '0'
    direction = request.forms.get('direction') or 'n'
    subprocess.call("echo -ne " + color + speed + direction + "> /dev/ttyS1", shell=True)
    return form

run(host='0.0.0.0', port=81)
