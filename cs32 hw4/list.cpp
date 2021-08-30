
void listAll(const File* f, string path)  // two-parameter overload
{
    
    path += "/";
    path += f->name();
    cout << path << endl;
    
    if (f->files() == nullptr) return; // base condition
    
    vector <File*> :: const_iterator it = f->files()->begin();
    
    
    while (it != f->files()->end()){
        listAll (*it, path);
        it++;
    }

}
