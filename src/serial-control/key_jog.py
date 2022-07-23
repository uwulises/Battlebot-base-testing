from serial_control import SerialControl
import time
from pynput.keyboard import Key, Listener, KeyCode

robot = SerialControl(port="COM4")
robot.open_serial()


def on_press(key):
    if key == Key.up:
        robot.forward()
    if key == Key.down:
        robot.backward()
    if key == Key.left:
        robot.turn_left()
    if key == Key.right:
        robot.turn_right()
    
def on_release(key):
    #print('{0} release'.format(key))
    if key == Key.esc:
        # Stop listener
        print('{0} release'.format(key))
        return False
    if key == Key.up:
        robot.stop()
    if key == Key.down:
        robot.stop()
    if key == Key.left:
        robot.stop()
    if key == Key.right:
        robot.stop()
# Collect events until released
with Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()
