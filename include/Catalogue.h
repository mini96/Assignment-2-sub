#ifndef CATALOGUE_H
#define CATALOGUE_H


class Catalogue
{
    public:
        Catalogue() {}
        int getKey(){return id;}
        void setKey(int k) {
        id = k;
        }
        virtual ~Catalogue() {}

    protected:
     int id;

    private:
};

#endif // CATALOGUE_H
