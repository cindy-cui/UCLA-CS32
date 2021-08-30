

class Investment{
    public:
    Investment(string n, int p){//constructor
        namex = n;
        price = p;
    }
    virtual ~Investment(){
    }
    
     string name() const{
         return namex;
     }
    
        virtual bool fungible() const = 0;
    
        virtual int purchasePrice() const {
            return price;
        }
    
        virtual string description() const = 0;
    
    private:
        string namex;
        int price;
        
};
class Painting: public Investment{
    
    public:
        Painting (string name, int cost): Investment( name, cost){ //constructor
          
        }
        virtual ~Painting(){ //destructor
            cout << "Destroying " << name() << ", a painting" << endl;
        }

        virtual bool fungible() const{
            return false;
        }
        
        
        virtual string description()const{
            return "painting";
        }
    
};

class Stock: public Investment{
    public:
        Stock (string name, int cost, string ticker) : Investment (name, cost){
            symbol = ticker;
        }
        virtual ~Stock(){ //destructor
            cout << "Destroying " << name() << ", a stock holding" << endl;
        }

        virtual bool fungible() const{
            return true;
        }
   
        
        virtual string description()const{
            return "stock trading as "+ symbol;
        }
    private:
        string symbol;
      
};


class House: public Investment{
    public:
        House (string name, int cost) : Investment (name, cost){
           
        }
        virtual ~House(){ //destructor
            cout << "Destroying the house " << name() << endl;
        }

        virtual bool fungible() const{
            return false;
        }

        virtual string description()const{
            return "house";
        }
    

};


