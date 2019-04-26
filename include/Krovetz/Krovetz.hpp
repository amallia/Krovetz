#pragma once

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

namespace stem {
class Krovetz {
    static const int MAX_WORD_LENGTH = 25;

    static const std::unordered_set<std::string> exceptions;

    static const std::unordered_map<std::string, std::string> conflations;

    static const std::unordered_set<std::string> headwords;

    static bool exists(const std::string& word) {
        auto exception_it = exceptions.find(word);
        if (exception_it != exceptions.end()) {
            return true;
        }
        auto conflations_it = conflations.find(word);
        if (conflations_it != conflations.end()) {
            return true;
        }
        auto headwords_it = headwords.find(word);
        if (headwords_it != headwords.end()) {
            return true;
        }
        return false;
    }

    static bool ends_with(const std::string& str, const std::string& suffix) {
        return str.size() >= suffix.size() &&
               std::equal(suffix.rbegin(), suffix.rend(), str.rbegin());
    }

    static bool is_consonant(const std::string word, size_t position) {
      char c = word[position];
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return false;
      } else if (c != 'y' || i == 0){
        return true
      } else {
        c = word[i - 1];
          return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
      }
    }

    static bool ends_with_double_consonant(const std::string word){
      if(word.size() == 1) return false;
          if (word[word.size() - 1] != word[word.size() - 2]){
              return false;
          }
          return is_consonant(word, word.size()-1);
    }


    /* convert plurals to singular form, and `-ies' to `y' */
    static void stem_plural(std::string& word) {
        if (ends_with(word, "s")) {
            if (ends_with(word, "ies")) {
                //   word[j+3] = '\0';
                //   k--;
                //   if (lookup(word))         ensure calories -> calorie
                //     return;
                //   k++;
                //   word[j+3] = 's';
                //   setsuffix("y");
            } else {
                if (ends_with(word, "es")) {
                    /* try just removing the "s" */
                    //   word[j+2] = '\0';
                    //   k--;

                    //   /* note: don't check for exceptions here.  So, `aides' -> `aide',
                    //      but `aided' -> `aid'.  The exception for double s is used to prevent
                    //      crosses -> crosse.  This is actually correct if crosses is a plural
                    //      noun (a type of racket used in lacrosse), but the verb is much more
                    //      common */

                    //   if ((lookup(word))  && j>0 && !((word[j] == 's') && (word[j-1] == 's')))
                    //     return;

                    //    try removing the "es"

                    //   word[j+1] = '\0';
                    //   k--;
                    //   if (lookup(word))
                    //     return;

                    //   /* the default is to retain the "e" */
                    //   word[j+1] = 'e';
                    //   word[j+2] = '\0';
                    //   k++;
                    //   return;
                } else {
                    //   if (wordlength > 3 && penult_c != 's' && !ends_in("ous")) {
                    //     /* unless the word ends in "ous" or a double "s", remove the final "s" */
                    //     word[k] = '\0';
                    //     k--;
                    //   }
                }
            }
        }
    }
    static void stem_past_tense(std::string& word) {}
    static void stem_aspect(std::string& word) {}
    static void stem_ment_endings(std::string& word) {}
    static void stem_ion_endings(std::string& word) {}
    static void stem_er_and_or_endings(std::string& word) {}
    static void stem_ly_endings(std::string& word) {}
    static void stem_al_endings(std::string& word) {}
    static void stem_ive_endings(std::string& word) {}
    static void stem_ize_endings(std::string& word) {}

    static void stem_ity_endings(std::string& word) {
      if (ends_with(word, "ity")) {
        std::string original_word = word;
        word.erase(word.size() - 3);
        if (exists(word)) return;
        word.push_back('e');
        if (exists(word)) return;
        word = original_word;
        if (ends_with(word, "ility")) {
          word[word.size() - 1] = 'a';

        }

      }
    }

    static void stem_ble_endings(std::string& word) {
      if (ends_with(word, "able") || ends_with(word, "ible")) {
        std::string original_word = word;

        word.erase(word.size() - 4);
        if (exists(word)) return;
        if (doublec(k))  {
          word.erase(word.size() - 1);
          if (exists(word)) return;
          word.push_back(word[word.size() - 1]);
        }
        word.push_back('e');
        if (exists(word)) return;
        word[word.size() - 1] = 'a';
        word.push_back('t');
        word.push_back('e');
        if (exists(word)) return;
        word = original_word;
      }
    }

    static void stem_ness_endings(std::string& word) {
      std::string ending = "ness";
      if (ends_with(word, ending)) {
        word.erase(word.size() - ending.size());
        if (word[word.size() - 1] == 'i')
          word[word.size() - 1] = 'y';
      }
    }

    static void stem_ism_endings(std::string& word) {
      std::string ending = "ism";
      if (ends_with(word, ending)) {
        word.erase(word.size() - ending.size());
      }
    }

    static void stem_ic_endings(std::string& word) {
      if (ends_with(word, "ic")) {
        std::string original_word = word;
        word.push_back('a');
        word.push_back('l');
        if (exists(word)) return;
        word.erase(word.size() - 3);
        word[word.size() - 1] = 'y';
        if (exists(word)) return;
        word[word.size() - 1] = 'e';
        if (exists(word)) return;
        word.erase(word.size() - 1);
        if (exists(word)) return;
        word = original_word;
      }
    }

    static void stem_ncy_endings(std::string& word) {
        if (ends_with(word, "ency") || ends_with(word, "ancy")) {
          word.erase(word.size() - 1);
          word[word.size() - 1] = 't';
          if (exists(word)) return;
          word[word.size() - 1] = 'c';
          word.push_back('e');
        }
    }

    static void stem_nce_endings(std::string& word) {
        if (ends_with(word, "ence") || ends_with(word, "ance")) {
            std::string original_word = word;
            word.erase(word.size() - 3);
            word[word.size() - 1] = 'e';
            if (exists(word)) return;
            word.erase(word.size() - 1);
            if (exists(word)) return;
            word = original_word;
        }
    }

   public:
    std::string stem(const std::string& word) const {
        std::string stem = word;
        std::transform(stem.begin(), stem.end(), stem.begin(), ::tolower);

        if (stem.size() <= 1 || stem.size() >= MAX_WORD_LENGTH) {
            return stem;
        }

        std::vector<std::function<void(std::string& word)>> functions = {
          &Krovetz::stem_plural,
          &Krovetz::stem_past_tense,
          &Krovetz::stem_aspect,
          &Krovetz::stem_ity_endings,
          &Krovetz::stem_ness_endings,
          &Krovetz::stem_ion_endings,
          &Krovetz::stem_er_and_or_endings,
          &Krovetz::stem_ly_endings,
          &Krovetz::stem_al_endings,
          &Krovetz::stem_ive_endings,
          &Krovetz::stem_ize_endings,
          &Krovetz::stem_ment_endings,
          &Krovetz::stem_ble_endings,
          &Krovetz::stem_ism_endings,
          &Krovetz::stem_ic_endings,
          &Krovetz::stem_ncy_endings,
          &Krovetz::stem_nce_endings};

        for(auto f: functions){
          if(exists(stem)) break;
            f(stem);
        }

        if(exists(stem)) return stem;
        return stem;
    }
};
}  // namespace stem