from flask import Flask, render_template, request
app = Flask(__name__)

@app.route('/')
def index():
  return render_template('index.html')

@app.route('/my-link/')
def my_link():
  print 'I got clicked!'

  return 'Click.'

@app.route('/ips', methods=['GET', 'POST'])
def ips():
    if request.method == 'POST':
        return 'bleh'
    else:
        return url_for('static', filename='ips.txt')

if __name__ == '__main__':
  app.run(debug=True)