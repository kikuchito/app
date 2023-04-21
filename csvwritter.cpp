#include <csvwriter.h>
#include <Carr.h>
#include <fstream>
bool CsvR::open(const QString& fname)
{
     fin.open(fname.toLatin1().data());
     return fin.is_open();
}
if (!fout.is_open()) { // Проверка, открылся ли файл:
  std::cout << "Error! File is not open" << std::endl;
} else {
    for (int i = 0; i < int(vec.size()); i++) {
      fout << vec[i] << std::endl;
    }
}
fout.close();
