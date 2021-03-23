    int y1 = stoi(s.substr(0, 4)), m1 = stoi(s.substr(4, 2)), d1 = stoi(s.substr(6, 2));
    if (y1 % 4 == 0 && !(y1 % 100) || y1 % 400 == 0) m[2]++;
    if (m1 < 1 || m1 > 12) {
        return 0;
    }
    if (d1 < 1 || d1 > m[m1]) {
        return 0;
    }
    return 1;