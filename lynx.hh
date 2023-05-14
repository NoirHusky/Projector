#include <string>

enum class LynxType { TITLE, URL };

struct LynxData {
    std::string url;
    std::string title;
};

struct LynxQuery {
    std ::string url;
    std ::string title;
    unsigned limit;

    template <typename T> LynxQuery &With(LynxType type, T data);
    static void Reset();
};

class Lynx {
  public:
    static void Load();
    static LynxQuery QueryBuilder();

    static void Add(std::string title, std::string url);
    template <class T> static void Remove(LynxType type, T payload);
    static bool Affect();
    static void Save();
};
