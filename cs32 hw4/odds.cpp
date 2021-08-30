

void removeOdds(vector<int>& v)
{
    vector <int> :: iterator it;
    for (int i = 0; i < v.size(); i++){
        if (v[i] % 2 == 1){
            it = v.begin() + i;
            v.erase(it);
            i--;
        }
    }

}
