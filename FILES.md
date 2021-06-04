main.cpp
--------
starts MainWindow window

MyGraphicsScene.h
-----------------
holds definition of MyGraphicsScene class

### MyGraphicsScene.cpp
holds implementation of MyGraphicsScene class
+ reimplements mouse press, mouse move and mouse release (to implement drawing custom sized shapes)
+ reimplements selectionChanged (for modifying multible shapes at once (!not yet implemented))

MyGraphicsView.h
----------------
holds definition for MyGraphicsView class

### MyGraphicsView.cpp
holds implementation of MyGraphicsView class
+ reimplements mouse wheel to add zooming
+ resizeScene function (dynamically resizes scene so it appears endless)

MainWindow.h
------------
main header file for MainWindow window <br>
imports MyGraphicsScene.h and MyGraphicsView.h
is imported by all .cpp files in project

### toolDock.cpp
holds toolDock code that is not in MainWindow's constructor
+ slots for toolDock's buttons

### createShapes.cpp
holds function for creating shapes
+ createShapeClickSlot slot (calls proper shapes creation function, depending on shapeId passed in)
+ createRect function (create rectangle at given coordinates)
+ createCircle function (creates circle at given coordinates)
+ createSquare function (creates square at given coordinates)

### MainWindow.cpp
holds MainWindow's code that does not go in other files
+ MainWindow's constructor