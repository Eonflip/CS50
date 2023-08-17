import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    if request.method == "GET":
        stocks = db.execute("""SELECT symbol, SUM(shares) as total_shares
                            FROM transactions
                            WHERE user_id = ?
                            GROUP BY symbol
                            HAVING total_shares > 0""",
                            session["user_id"])
        stock_total = 0
        for stock in stocks:
            stock_data = lookup(stock["symbol"])
            stock["name"] = stock_data["name"]
            stock["price"] = stock_data["price"]
            stock_total += stock_data["price"] * stock["total_shares"]

        current_cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash_amount = current_cash[0]["cash"]
        total_cash = cash_amount + stock_total


        return render_template("index.html", stocks=stocks, cash_amount=cash_amount, total_cash=total_cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")

    if request.method == "POST":

        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        if not symbol:
            return apology("Missing Symbol", 403)
        if not shares:
            return apology("Missing Shares", 403)

        result = lookup(symbol)

        if result:
            total_price = result["price"] * shares
            current_cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
            cash_amount = current_cash[0]["cash"]

            if total_price > cash_amount:
                return apology("Not enough cash", 403)

            db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", total_price, session["user_id"])

            db.execute("INSERT INTO transactions (user_id, symbol, shares, price_per_share, transaction_type) VALUES (?, ?, ?, ?, 'BUY')", session["user_id"], symbol, shares, result["price"])

            return redirect("/")
    else:
        return apology("Invalid Symbol", 403)


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("/quote.html")
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("Missing Symbol", 403)
        result = lookup(symbol)
        if (result):
            return render_template("/quoted.html", symbol=symbol, lookup=result["price"])
        else:
            return apology("Invalid Symbol", 403)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        pass_confirm = request.form.get("pass_confirm")

        if not username:
            return apology("must provide username", 403)
        if not password:
            return apology("must provide password", 403)
        if not pass_confirm:
            return apology("must confirm password", 403)
        if pass_confirm != password:
            return apology("passwords must match", 403)

        existing_user = db.execute("SELECT * FROM users WHERE username = ?", username)
        if existing_user:
            return apology("username already exists", 403)

        hashed_password = generate_password_hash(password)
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hashed_password)

        return redirect("/login")
    else:
        return render_template("/register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":
        stocks = db.execute("""SELECT symbol, SUM(shares) as total_shares
                            FROM transactions
                            WHERE user_id = ?
                            GROUP BY symbol
                            HAVING total_shares > 0""",
                            session["user_id"])
        return render_template("/sell.html")

    if request.method == "POST":
    return apology("TODO")
