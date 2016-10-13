#include<iostream>
#include<string>
#include<vector>

using namespace std;

class robopart {
	private:
		vector <int> number;
		vector <double> cost, weight;
		vector <string> description, name;
		int i;
	public:
		void store(string nam, int num, double w, double c, string desc) {
			name.push_back(nam);
			number.push_back(num);
			weight.push_back(w);
		    cost.push_back(c);
			description.push_back(desc);
		};
		void print() {
			cout << "\n";
			for (i = 0; i < name.size(); i++)
				if (name[i] != "0")
					cout << i << " " << name[i] << ", " << number[i] << ", " << weight[i] << ", " << cost[i] << ", " << description[i] << "\n";
			cout << "\n";
		}
		void removeline(int line)
		{
			i = 0;
			while (i < line)
				i++;

		    name[i] = "0";

			cout << "number: " << line << " has been removed!\n";
			i = 0;
		}
		double gcost(int line) {return cost[line];}
};

class robomodel {
	private:
		vector <double> cost;
		vector <string> name, description;
		vector <int> number;
		vector <double> sellingprice;
		vector <double> shippingprice;
		int i,total;
	public:

		void print() {
			cout << "\nList of Models: ";
			for (i = 0; i < name.size(); i++)
				cout << "\n_______________________________\n\nModel #" << i <<"\nName of Model: " << name[i] << "\nProduct Number: " << number[i] << "\nSelling Price: " << sellingprice[i] << "\nShipping Cost: " << shippingprice[i] << "\nDescription: " << description[i] <<"\n";
			
	}
		void store(double c, string modelname, int modelnumber, double shipping, double sellprice, string desc) {
			cost.push_back(c);
			name.push_back(modelname);
			number.push_back(modelnumber);
			shippingprice.push_back(shipping);
			sellingprice.push_back(sellprice);
			description.push_back(desc);
	}
		double purchase(int line)
		{
			i = 0;
			while (i < line)
				i++;

			total = sellingprice[i] + shippingprice[i];
			cout << "Thank you for purchasing " << name[i] << "!\n";
			return total;
		}
		string decision(int line){
			i = 0;
			while (i < line)
				i++;
			return name[i];
		}
};

class unapproved {
	private:
		vector <string> name, date, model;
		vector <double> price;
		int i,inc;
	public:
		void store(string nam, double p, string d, string m) {
			name.push_back(nam);
			price.push_back(p);
			date.push_back(d);
			model.push_back(m);
		};
		void print() {
			cout << "\n";
			for (i = 0; i < name.size(); i++)
					cout << i << " " << name[i] << ", " << model[i] << ", " << price[i] << ", " << date[i] << "\n";
			cout << "\n";
		}
		int search(string nam){
			inc == 0;
			for (i = 0; i < name.size(); i++)
			{
				if (nam == name[i])
				{
					cout << i << " " << name[i] << ", " << model[i] << ", " << price[i] << ", " << date[i] << "\n";
					inc++;
				}
			}
			return inc;
		}
};



