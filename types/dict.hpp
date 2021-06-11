#include <string>
#include <vector>
#include <exception>

using namespace std;


class Key_Already_Exists: public exception {
	public: const char *what() const throw() {return "an identical key alreay exists in this context";}
};

class Key_Does_Not_Exist: public exception {
	public: const char *what() const throw() {return "the key could not be found in this context";}
};

template <typename T>
struct Pair {
	string key;
	T value;
	Pair(string key, T value): key(key), value(value) {}
};

template <typename T>
class Dictionary {
	vector<Pair<T>> content;
	int findindex(string key) {
		for(int i = 0; i < content.size(); i++) {
			if(content[i].key == key) {return i;}
		}
		throw Key_Does_Not_Exist();
	}
	bool keyexists(string key) {
		try {
			int x = findindex(key);
			return true;
		}catch(Key_Does_Not_Exist) {
			return false;
		}
	}
	public:
		Dictionary() {}
		Dictionary(vector<Pair<T>> input) : content(input) {}
		void push(string key, T value) {
			if(keyexists(key)) {throw Key_Already_Exists();}
			content.push_back(Pair<T>(key, value));
		}
		T &operator[](string key) {
			return content.at(findindex(key));
		}
};