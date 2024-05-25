import headset
from headset import Headset
import serial
import time
import json

def getCredentials():
    file = open('pass.txt', 'r')

    credentials = {}

    credentials["token"] = file.readline().strip().replace('token: ', '')

    credentials["id"] = file.readline().strip().replace('id: ', '')

    credentials["profile_name"] = file.readline().strip().replace('profile_name: ', '')

    file.close()
    return credentials


if __name__ == "__main__":
    time.sleep(2)
    credentials = getCredentials()

    client_id = credentials["id"]
    client_secret = credentials["token"]
    profile_name = credentials["profile_name"]

    try:
        headset = Headset(client_id, client_secret)
        headset.start(profile_name, "EPOCX-E5020776")
        print("Headset connected")
        headset.subscribe_data(['com'])
    except KeyboardInterrupt:
        print("Interrupted by user, stopping...")
    finally:
        print("Program stopped.")


    
#c data: {'action': 'neutral', 'power': 0.0, 'time': 1715171786.76}
#the JSON object must be str, bytes or bytearray, not dict


#mc data: {'action': 'neutral', 'power': 0.0, 'time': 1715171955.691}
#{"action": "neutral", "power": 0.0, "time": 1715171955.691}
#name 'power' is not defined
#mc data: {'action': 'neutral', 'power': 0.0, 'time': 1715171955.8161}
#{"action": "neutral", "power": 0.0, "time": 1715171955.8161}
#name 'power' is not defined
#mc data: {'action': 'neutral', 'power': 0.0, 'time': 1715171955.9407}

#action:push,power:0.0

    
