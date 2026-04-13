template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
    int probes = 0;
    for (int i = 0; i < M; i++) {
        int idx = probeIndex(key, i);
        probes++;
        if (!occupied[idx]) {
            table[idx] = key;
            occupied[idx] = true;
            N++;
            return probes;
        }
    }
    throw runtime_error("Hash table is full");
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO: 
    for (int i = 0; i < M; i++) {
        int idx = probeIndex(key, i);
        if (!occupied[idx]) return {false, 0}; // not found
        if (table[idx] == key) return {true, idx}; // found
    }
    return {false, M};
}
