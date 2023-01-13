# Adafruit-Arm
This is the code to run the Adafruit controlled arm. Parts include:
- 1 Arm with jointed fingers and holes to those jointed fingers, allowing fishline to be threaded through
- 1 Arduino
- 1 Adafruit 16 servo sheild
- 5 REV Smart Robot Servos
- 5 Regular Arduino Buttons
- 5 10K Ohm Resistors
- Enough female to male wires for all the button wiring
<br>
To run succesfully, you need to calibrate the arm. Directions are below

# Variable Names
servos are:
```
servonumINDEX = [YOURIDHERE]
servonumMIDDLE = [YOURIDHERE]
servonumRING = [YOURIDHERE]
servonumPINKY = [YOURIDHERE]
servonumTHUMB = [YOURIDHERE]
```

buttons are:
```
buttonnumINDEX = [YOURIDHERE]
buttonnumMIDDLE = [YOURIDHERE]
buttonnumRING = [YOURIDHERE]
buttonnumPINKY = [YOURIDHERE]
buttonnumTHUMB = [YOURIDHERE]
```

# Calibrating Max Contract and Release Positions
To do this, you must first do this with any servo WITHOUT the fishline attached. In your code, use the `moveFingy(servonum, degrees)` function and set the degrees to a random number (preferably 0 or 180, if those don't work go 10 higher (for 0) or lower (for 180)). If you get movement that would contract the finger, the number that you used right before that number (10 lower or higher than that number, depending on which number you chose) is your `maxRelease` number for that finger. 
<br>
<br>
Now, attach a fishline so it has a little slack, but not too much. You should get a little movement and a low chord when plucking the string. In your code, go by increments of 10 opposite of your `maxRelease` number (180→170, 0→10) until the finger is fully contracted. This is your `maxContract` number for that finger. If the chord is too tight for your liking, you can go 10 less.
<br>
<br>
Repeat for all servos. When done, test by moving all fingers to their `maxContract` and `maxRelease` positions. If all work, congratulations! you can now move all the fingers in between these maxes.
