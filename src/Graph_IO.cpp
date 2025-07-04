#include "Graph_IO.h"


std::ofstream& operator<<(std::ofstream& os, const IGraph& Graph)
{
    os << "[Graph]\n";
    os << "isDirected : " << Graph.is_Directed() << "\n";
    os << "isWeighted : " << Graph.is_Weighted() << "\n";

    for (auto const v : Graph.vertices())
    {
        os << "v : " << v->id() << "\n";
    }
    os << "\n";

    for (auto const e : Graph.edges())
    {
        os << "e : " << e->from()->id() << " -> " << e->to()->id() << " | " << e->weight() << "\n";
    }
    return os;
}

bool eol_test(std::istream& is);

std::ifstream& operator>>(std::ifstream& is,IGraph& Graph)
{
    if (is.eof()){ throw read_error("Datei ist Leer"); }
    if (is.bad() || is.fail()) {throw read_error("Zeile 0: Unbekannter Fehler!");}
    bool isDirected = false;
    bool isWeighted = false;
    std::vector<int> vertices;
    std::vector<std::vector<int>> edges;
    std::string test_string;
    char test_char;
    int number1 = 0;
    int number2 = 0;
    int number3 = 0;
    int line_count = 0;

    is >> test_string;
    if (!eol_test(is) || test_string != "[Graph]")
    {
        throw read_error("Zeile 0: Einlese Fehler");
    }
    if (is.eof() or is.fail()){throw read_error("Zeile: " + std::to_string(line_count) + " Einlese Fehler");}
    line_count++;
    // IS DIRECTED
    is >> test_string;
    is >> test_char;
    if (test_string != "isDirected" || is.fail() || test_char != ':')
    {
        throw read_error("Zeile: " + std::to_string(line_count) + " Einlese Fehler");
    }
    is >> number1;
    if (is.fail() || !eol_test(is) || number1 > 1 || number1 < 0 )
    {
        throw read_error("Zeile: " + std::to_string(line_count) + " Erwartete \"isDirected : <0/1>\"");
    }
    if (number1 == 1){isDirected = true;}
    line_count++;
    // IS WEIGHTED
    if (!is.good()){ throw read_error("Zeile: " + std::to_string(line_count) + " Erwartete \"isDirected : <0/1>\"");}
    is >> test_string;
    is >> test_char;
    if (test_string != "isWeighted" || is.fail() || test_char != ':')
    {
        throw read_error("Zeile: " + std::to_string(line_count) + " Erwartete \"isWeighted : <0/1>\" ");
    }
    is >> number1;
    if (is.fail() || !eol_test(is) || number1 > 1 || number1 < 0)
    {
        throw read_error("Zeile: " + std::to_string(line_count) + "Erwartete \"isWeighted : <0/1>\" ");
    }
    if (number1 == 1){isWeighted = true;}

    // KNOTEN EINLESEN
    if (is.eof()){return is; } // LEERER GRAPH -> AN SICH OKAY

    is >> test_char;
    if (test_char != 'v'){throw read_error("Zeile: " + std::to_string(line_count) + " Einlese Fehler");}
    while (test_char == 'v')
    {
        if (is.fail()){ throw read_error("Zeile: " + std::to_string(line_count) + " Erwartete Knoten in Format: \"v : <ID>\"");}
        is >> test_char;
        if (eol_test(is) || test_char != ':')
        {
            throw read_error("Zeile: " + std::to_string(line_count) + " Erwartete Knoten in Format: \"v : <ID>\"");
        }
        is >> number1;
        if (!eol_test(is) || is.fail() && !is.eof())
        {
            throw read_error("Zeile: " + std::to_string(line_count) + " Erwartete Knoten in Format: \"v : <ID>\"");
        }
        vertices.push_back(number1);
        line_count++;
        if (!is.eof()) {is >> test_char;}
        else{ test_char = 'x';}
    }
    char test_char2;
    char test_char3;
    while (test_char == 'e')
    {
        if (is.fail()){throw read_error("Zeile: " + std::to_string(line_count) + " Erwartete Kanten in Format: \"e : <ID> -> <ID> | <WEIGHT> \"");}
        is >> test_char;
        is >> number1;
        is >> test_char2;
        is >> test_char3;
        if (test_char != ':' || test_char2 != '-' || test_char3 != '>' || !is.good())
        {
           throw read_error("Zeile: " + std::to_string(line_count) + " Erwartete Kanten in Format: \"e : <ID> -> <ID> | <WEIGHT> \"");
        }
        is >> number2;
        is >> test_char;
        is >> number3;
        if (!eol_test(is) || !is.good() && !is.eof())
        {
             throw read_error("Zeile: " + std::to_string(line_count) + " Erwartete Kanten in Format: \"e : <ID> -> <ID> | <WEIGHT> \"");
        }
        std::vector<int> t = {number1,number2,number3};
        edges.push_back(t);
        line_count++;
        if (is.eof())
        {
            test_char = 'x';
        }
        else
        {
            is >> test_char;
        }
    }
    // NOCH EIN TEST??


    Graph.set_Weighted(isWeighted);
    Graph.set_Directed(isDirected);
    for (int i : vertices)
    {
        Graph.create_vertex(i);
    }
    for (auto t : edges)
    {
        Graph.create_edge(t[0],t[1],t[2]);
    }
    return is;
}


bool eol_test(std::istream &is) {
    if (is.eof()) {return true;} // !! NEUE ZEILE!! SOLLTE DAS EOF PROBLEM FIXXEN DASS EOL DAS ERGEBNIS VON EOF ÄNDERT INDEM ES DIE LETZTE IS AUSGABE UNGETTET!!
    // Falls nicht EOF ist wird nach EOL geprüft (Eol = end of line)
    char temp = 't';
    is.get(temp);

    while (temp == ' ' && !is.eof())    // Es werden zeichen eingelesen, und auf eof geprüft. Diese prüfung kommt häufig vor da es nicht immer wie
    {                                   // Gewollt geklappt hat (Eol test buggt teilweise bei EOF, da unendlich ws gelesen wird) -> Es wird auch auf EOF geprüft
        is.get(temp);                   // (EIGL JZ GEFIXXT) --> MAYBE VERKÜRZUNGEN MÖGLICH
    }

    if (temp == '\n' or is.eof())   // Sollte EOL sein, ist er true
    {
        return true;
    }
    is.unget(); // wird ein zeichen ungleich \n und es ist kein Eof, so wurde ein Zeichen gelesen, dieses muss wieder zurückgegeben werden
    return false;   // Dieses Zeichen könnte z.b. ein Indikator sein dass zu viele Argumente geliefert wurden
}