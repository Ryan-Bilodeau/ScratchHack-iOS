import datetime


class Ticket:
    name: str
    number: str
    price: str
    odds: str
    printDate: str

    prizeAmount: []
    prizesPrinted: []
    prizesRemaining: []

    date: str

    def __init__(self):
        time = datetime.datetime.now()
        year = time.year
        month = time.month
        if month < 10:
            month = "0" + str(time.month)
        day = time.day
        if day < 10:
            day = "0" + str(time.day)
        self.date = "{y}{m}{d}".format(y=year, m=month, d=day)

        self.prizeAmount = []
        self.prizesPrinted = []
        self.prizesRemaining = []