#include <iostream>
using namespace std;

// Your end product 
class AppleProduct{
    string _product;
    string _input;
    string _processor;
    string _price;
    string _storage;

public:

    AppleProduct(string set_product) { _product = set_product; }

    void setProcessor(string set_processor) { _processor = set_processor; }

    void setPrice(string set_price) { _price = set_price; }

    void setStorage(string set_storage) { _storage = set_storage; }

    void setInput(string set_input) { _input = set_input; }
    string getProcessor() { return _processor; }
    string getInput() { return _input; }
    string getPrice() { return _price; }
    string getStorage() { return _storage; }
    
    void show() {
    	cout << "Apple Base Product Info: " <<_product << endl;
      cout << "Input Type: " <<_input << endl;
    	cout << "Processor Type: "<<_processor << endl;
      cout << "Storage Amount: "<<_storage << endl;
      cout << "Average Price: "<<_price << endl <<endl;

    }
};

// AppleProductBuilder Abstract Class all builders should have at least these methods
class AppleProductBuilder{
protected:
    AppleProduct *_apple_product;
public:
    virtual void getOtherParts() = 0;
    virtual void buildInput() = 0;
    virtual void buildProcessor() = 0;
    virtual void buildStorage() = 0;
    virtual void buildPrice() = 0;
    AppleProduct* getAppleProduct(){ return _apple_product; }
};

// AppleProductBuilder concrete class knows only how to build iPhone AppleProduct!
class iPhoneBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for iPhone"); }

    void buildProcessor() { _apple_product->setProcessor("Apple ARM Processor");   }

    void buildInput() { _apple_product->setInput("Touchscreen Input");   }
    
    void buildPrice() {_apple_product->setPrice("$700"); }

    void buildStorage() {_apple_product->setStorage("64gb"); }
};

// AppleProductBuilder concrete class knows only how to build Mac AppleProduct
class MacBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for Mac"); }

    void buildProcessor() { _apple_product->setProcessor("Intel Core Processor"); }

    void buildInput() { _apple_product->setInput("Mouse and Keyboard Input");   }

    void buildPrice() {_apple_product->setPrice("$1500"); }

    void buildStorage() {_apple_product->setStorage("512GB"); }
};

class IPadBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for IPad"); }

    void buildProcessor() { _apple_product->setProcessor("Octa-Core Apple A12X Bionic"); }

    void buildInput() { _apple_product->setInput("Touch Screen");   }

    void buildPrice() {_apple_product->setPrice("$999"); }

    void buildStorage() {_apple_product->setStorage("64GB"); }
};

class ApplePencilBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for Apple Pencil"); }

    void buildProcessor() { _apple_product->setProcessor("NONE"); }

    void buildInput() { _apple_product->setInput("Touch");   }

    void buildPrice() {_apple_product->setPrice("$129"); }

    void buildStorage() {_apple_product->setStorage("NONE"); }
};
// Defines steps and tells to the builder that build in given order.
class Director{

    AppleProductBuilder *builder;

public:

    AppleProduct* createAppleProduct(AppleProductBuilder *builder) {
        builder->getOtherParts();
        builder->buildInput();
        builder->buildProcessor();
        builder->buildStorage();
        builder->buildPrice();
        return builder->getAppleProduct();
    }
};

int main() {
	
  Director dir;
  MacBuilder mb;
  iPhoneBuilder ib;
  ApplePencilBuilder apb;
  IPadBuilder ipb;

	AppleProduct *mac = dir.createAppleProduct(&mb);
	AppleProduct *iphone = dir.createAppleProduct(&ib);
  AppleProduct *applepencil = dir.createAppleProduct(&apb);
  AppleProduct *ipad = dir.createAppleProduct(&ipb);
	
	mac->show();
  delete mac;

	iphone->show();
  delete iphone;  

  applepencil->show();
  delete applepencil;

  ipad->show();
  delete ipad;
    
	return 0;
}