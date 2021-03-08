class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        std::string emptystr;
        std::string tmps=s;
        int longest=0;
        std::string answer(1000, 'z');
        for (int i=0; i<d.size(); i++) {
            for (int j=0; j<d[i].length(); j++) {
                // std::cout << "i=" << i << ", j="<< j << ", d[i][j]=" << d[i][j] << ", s=" << s << ", s.find(d[i][j])=" << (int)s.find(d[i][j]) << ". " ;
                // std::copy(d.begin(), d.end(), std::ostream_iterator<std::string>(std::cout, ","));
                // std::cout << std::endl;
                if ((int)s.find(d[i][j]) < 0) {
                    d[i]=emptystr;
                    break;
                } else if ((int)s.find(d[i][j]) == 0) {
                    s.erase(s.begin());
                } else {
                    s.erase(s.begin(), s.begin()+(int)s.find(d[i][j])+1);
                }
            }
            s=tmps;
            if (d[i].length()>longest) {
                longest=d[i].length();
            }
            // std::cout << "longest=" << longest << "\n";
        }
        for (int k=0; k<d.size(); ) {
            if (d[k].length()!=longest) {
                d.erase(d.begin()+k);
            } else {
                if (d[k]<answer) {
                    answer=d[k];
                }
                k++;
            }
            // std::copy(d.begin(), d.end(), std::ostream_iterator<std::string>(std::cout, ","));
            // std::cout << " answer=" << answer <<std::endl;
            
        }
        return answer;
    }
};
