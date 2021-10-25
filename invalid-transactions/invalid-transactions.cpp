class transaction {
public:
    int time;
    int amount;
    string city;
    string tran;
    bool marked;
    
    transaction (int t, int a, string c, string tr) {
        tran = tr;
        time = t;
        amount = a;
        city = c;
        marked = false;
    }
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        if(transactions.empty())
            return {};
        
        unordered_map<string, vector<transaction*>> trans;
        
        for(string &st : transactions) {
            istringstream ss(st);
            string token = "";
           
            getline(ss, token, ',');
            string name = token;
            getline(ss, token, ',');
            int time = stoi(token);
            getline(ss, token, ',');
            int amount = stoi(token);
            getline(ss, token, ',');
            string city = token;
            
            transaction *t = new transaction(time, amount, city, st);
            trans[name].push_back(t);
        }
        vector<string> result;
        
        for(auto &p : trans) {
           
            sort(p.second.begin(), p.second.end(), [](const transaction* a, const transaction* b) {
                return a->time < b->time;
            });
            for(int i=0; i<p.second.size(); i++) {
                
                if(p.second[i]->amount > 1000) {
                    result.push_back(p.second[i]->tran);
                    p.second[i]->marked = true;
                }
               
                if(i > 0 && p.second[i]->time <= p.second[i-1]->time + 60) {
                    int r = i-1;
                    while(r >= 0 && p.second[r]->time >= p.second[i]->time - 60) {
                        if(p.second[i]->city != p.second[r]->city) {
                            if(!p.second[r]->marked) {
                                result.push_back(p.second[r]->tran);
                                p.second[r]->marked = true;
                            }
                            if(!p.second[i]->marked) {
                                p.second[i]->marked = true;
                                result.push_back(p.second[i]->tran);
                            }
                        }
                        r--;
                    }
                }
            }
        }
        return result;
    }
};