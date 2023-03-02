/*
This code is to translate a given format into either chords for the plucker
to press on or a series of notes for the plucker to press, with their respective timings.
Another Function will be incorporated that controls the Servos that pluck.


The format of the singular notes will be:
[NotePosition,MS held]

Note position can be a tuple of the position (x and y)

For chords the format will be

[ChordObject, Ms held]

Chord object will be a class (if that exists in arduino) that will contain a list of
The solenoid locations which need to be held down. 

There will be atleast 2 functions:

PlaySong()

StrumSong()

These will take a queue of the above objects and play accordingly. (again only if the data structure exists)

Potentially, we can use Python to extract the information from MIDI files into the above format, so that this can easily be automated.



*/
