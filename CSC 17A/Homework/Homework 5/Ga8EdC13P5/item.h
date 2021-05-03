#ifndef ITEM_H
#define ITEM_H

class RetailItem
{
private:
    std::string description;
    int unitsOnHand;
    float price;
public:
    RetailItem(std::string, int, float);
    void setInfo(std::string, int, float);
    
    std::string outDesc() const
        { return description; }
    
    int outUnits() const
        { return unitsOnHand; }
    
    float outPrice()
        { return price; }
};


#endif /* ITEM_H */


