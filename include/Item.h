#ifndef ITEM_H
#define ITEM_H
class Item:public Catalogue
{
public:
    Item()
    {
    }

    virtual ~Item() {}
        string itemName;
        string description;
        double price;
        double maxDiscount;
        friend ostream& operator<<(ostream& os, const Item& dt);
protected:

private:
};
ostream& operator<<(ostream& os, const Item& dt)
{
    os << dt.itemName<< ", price : "<< dt.price;
    return os;
}





#endif // ITEM_H
