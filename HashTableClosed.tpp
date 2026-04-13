template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
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
    for (int i = 0; i < M; i++) {
        int idx = probeIndex(key, i);
        if (!occupied[idx]) return {false, i + 1};
        if (table[idx] == key) return {true, i + 1};
    }
    return {false, M};
}
