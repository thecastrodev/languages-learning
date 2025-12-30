import os
from flask import Flask
from database import db
from models.user import User
from dotenv import load_dotenv

load_dotenv()

app = Flask(__name__)
app.config["SECRET_KEY"] = os.environ.get("SECRET_KEY")
app.config["SQLALCHEMY_DATABASE_URI"] = os.environ.get("SQLALCHEMY_DATABASE_URI")

db.init_app(app)

@app.route("/hello-world", methods=["GET"])
def hello_world():
  return "Hello World"

if __name__ == "__main__":
  app.run(debug=True)
