# Project part 2 specs:

## The immutable Vector class:
The modelling of graphical objects consits modelling concepts such as location, movement, etc. The mathematial background that builds up these objects is the notion of "Vectors". 

In this part, we try to implement a Vector class `Vec`. We want this "Vector" to be an imuttable, meaning the attributes of Vector, once initialized, is not allowed to change. This corresponds to the mathematical "variable".

In order to use the vector in a intuitive manner, we further require you to implement a few operator overloads. An example of overload "+"  is given as an example. Search how to write operator overload. The function for each operator overload is provided in the following code:

```cpp
class Vec {
private:
    float x,y;
public:
    Vec(float _x, float _y) {
        x = _x; y = _y;
    }
    float getX() {return x;}
    float getY() {return y;}

    // Example Overloads + operator
    // returns the sum of 2 Vec
    Vec operator+ (Vec v) { 
        return Vec(x + v.getX(), y + v.getY());
    }

    // Overload - on 2 Vectors
    // return thier difference Vector

    // Overload * operator on a float k
    // return current Vector scaled by k 

    // Overload * on 2 Vectors
    // return thier inner product (scaler product)

    // Overload << on an angle
    // return current vector rotated counter clockwise
    // by this angle
    
    // Overload >> on an angle
    // return current vector rotated clockwise 
    // by this angle
};
```

Note you are allowed to add your own attributes and methods into this class, as long as you following rules below:

1. All attributes must be `private`
2. The class stays immutable. Meaning no method (except for constructors) is allowed to change any attributes in any circumstances.

## The Figure base class

We begin our modelling by first specifying what a graphical figure is. All figures can move, zoom, and rotate. All figures can be drawn out. It's natural to require all figures have these four methods. 

To ease our further work, we assume whenever we are zooming or rotating the object, it is rotated around a "central point" of that object, called "anchor point". It's similar to the idea of "center of mass" in physics.

Note that points are essentially vectors, we provide the following base class:

```cpp
class Figure () {
protected:
    Vec anchor;
public:
    Figure() : anchor(0, 0) {}

    Vec getAnchor() {return anchor}
    void setAnchor(Vec a) {anchor = a}

    virtual void draw() = 0;
    virtual void move(Vec dir) = 0;
    virtual void rotate(float angle) = 0;
    virtual void zoom(float k) = 0;

    virtual ~Figure() {}
} 
```

You can always add new attributes and methods into the class, as long as you follow the following rule:

1. All attributes must either be `private` or `protected`
2. This rule applied to all classes derived from this base class.

Also note that your implementation of the 3 operations must be consistent. Meaning, if the user call 
`move(Vec(3,0)); zoom(2); move(Vec(-3,0)); zoom(0.5);` subsequently，the figure should end up unchanged.

## The Group class

It turns out just the `Figure` class is insufficient to solve our problem. Comlicated figures are build up using smaller figures. We now seek to model a group of figures. 

We begin by first noticing that "a group of figures" is itself a "Figure". Secondly, a group of figure **"has"** some figures. Naturally a group of figure could "has" another `Group`. 

We give the following (incomplete) definition:

```cpp
class Group : Figure {
private:
    // A Group of figure "has" other figures.
public:
  
    // We left out the constructor as well

    void draw();      // Draw out all its figures
    void move(Vec dir);    // Move all its figures
    void rotate(float angle);    // Rotate the group as a whole.
    void zoom(float k);     // Zoom the group as a whole.
    ~Group() {}
}
```

We leave out some detail in this class. You are required to fill in them. You can add whatever you feel neccessary into the class. 

## The class relation graph:

To help you set up the structure, we provided the following UML: