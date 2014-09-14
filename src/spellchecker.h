#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H


class Hunspell;

class SpellChecker
{
public:
    SpellChecker();
    ~SpellChecker();
    void load_dict(const char *affpath, const char *dicpath);
    int spell(const char * word) const;
    int ready() const;

    enum Status {
        Null,
        Bad,
        Ok
    };

private:
    Hunspell *hs;
};

#endif // SPELLCHECKER_H
