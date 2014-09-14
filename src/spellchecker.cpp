#include "spellchecker.h"
#include <hunspell/hunspell.hxx>

SpellChecker::SpellChecker()
{
    hs = NULL;
}

SpellChecker::~SpellChecker()
{
    if (hs != NULL)
        delete hs;
}

int SpellChecker::ready() const
{  
    if (hs != NULL){
        if (hs->spell ("a")) {
            return Ok; // OK
        }
        return Bad; // seems not working properly
    } else {
        return Null; // hs not initialized
    }

}

int SpellChecker::spell(const char * word) const
{
    if (hs == NULL)
        return 0;

    return hs->spell (word);
}

void SpellChecker::load_dict (const char *affpath, const char *dicpath)
{
    if (hs != NULL)
        delete hs;
    hs = new Hunspell(affpath,dicpath, NULL);
}
