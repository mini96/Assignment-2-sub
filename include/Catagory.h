#ifndef CATAGORY_H
#define CATAGORY_H

class Catagory:public Catalogue
{
    public:
        Catagory() {}
        string categoryName;
        string description;
        virtual ~Catagory() {}
        int categoryKey=0;
        friend ostream& operator<<(ostream& os, const Catagory& dt);
    protected:

    private:
};

ostream& operator<<(ostream& os, const Catagory& dt)
{
    os << dt.categoryName;
    return os;
}

#endif // CATAGORY_H
