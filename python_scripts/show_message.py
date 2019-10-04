import sys
from sense_hat import SenseHat
sense = SenseHat()
sense.show_message(sys.argv[1])