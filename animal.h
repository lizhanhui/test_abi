#ifndef ANIMAL_H
#define ANIMAL_H


class animal
{
public:
    virtual ~animal() {

    }

    virtual void eat() = 0;

#ifdef TALK
    virtual void talk() = 0;
#endif

};

class dog : public virtual animal {
public:
    virtual void eat();

#ifdef TALK
    virtual void talk();
#endif

};

extern "C" {
    animal* lookup();
}

#endif // ANIMAL_H
