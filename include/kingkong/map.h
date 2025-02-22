#pragma once

/* includes */
#include <boost/algorithm/string/predicate.hpp>
#include <boost/functional/hash.hpp>
#include <unordered_map>

/**
 * @brief ci functions
 * @returns seed
 * 
 */
namespace kingkong {

    struct ci_hash
    {
        size_t operator()(const std::string& key) const
        {
            std::size_t seed = 0;
            std::locale locale;

            for(auto c : key)
            {
                boost::hash_combine(seed, std::toupper(c, locale));
            }

            return seed;
        }
    };

    /**
     * @brief ci key 
     * 
     */
    struct ci_key_eq
    {
        bool operator()(const std::string& l, const std::string& r) const
        {
            return boost::iequals(l, r);
        }
    };

    /**
     * @brief ci map
     * 
     */
    using ci_map = std::unordered_multimap<std::string, std::string, ci_hash, ci_key_eq>;
}