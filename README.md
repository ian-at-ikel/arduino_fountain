# arduino_fountain
Ardunio Nano controlled fountain water level monitor and fill-up

A float switch is used to determine the water-level. When the level is high, 
the float sits high in the water and the swtich is open. When the level drops,
the float falls and the switch is closed.
The arduino monitors the switch, and when it closes, the arduino closes a relay,
which in turn opens a solenoid valve that then fills the fountain. The solenoid
valve is hooked up to the mains-pressure water system in my garden.

When the water level is high, the arduino checks less frequently to see if the
level has dropped. When it is low, it checks more frequently to see if the
level is high again, so that it can open the relay and turn off the solenoid.
