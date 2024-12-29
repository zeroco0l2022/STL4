// STL4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <random>



static int random_number() {
 std::random_device rd;
 std::mt19937 gen(rd());
 std::uniform_int_distribution<> dis(0, 99);
   return dis(gen);
}

int main()
{
     // 1. Пример partial_sort_copy
   std::vector<int> source(15);
   std::generate(source.begin(), source.end(), random_number);
   std::vector<int> result(7); // Меньший размер для частичной сортировки
   
   std::cout << "Исходный массив: ";
   std::copy(source.begin(), source.end(), std::ostream_iterator<int>(std::cout, " "));
   std::cout << "\n";
   
   std::partial_sort_copy(source.begin(), source.end(), 
                         result.begin(), result.end());
   
   std::cout << "Частично отсортированная копия: ";
   std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
   std::cout << "\n\n";
    // 2. Пример lower_bound и upper_bound
   std::vector<int> arr = {10, 20, 30, 30, 30, 40, 50, 60, 70, 80};
   const int search_val = 30;

   const auto lower = std::lower_bound(arr.begin(), arr.end(), search_val);
   const auto upper = std::upper_bound(arr.begin(), arr.end(), search_val);
   
   std::cout << "Для значения " << search_val << ":\n";
   std::cout << "lower_bound на позиции: " << (lower - arr.begin()) << "\n";
   std::cout << "upper_bound на позиции: " << (upper - arr.begin()) << "\n\n";
    // То же самое с set
   std::set<int> number_set(arr.begin(), arr.end());
   const auto set_lower = number_set.lower_bound(search_val);
   const auto set_upper = number_set.upper_bound(search_val);
   
   std::cout << "В set:\n";
   std::cout << "lower_bound: " << *set_lower << "\n";
   std::cout << "upper_bound: " << *set_upper << "\n\n";
    // 3. Пример includes и set_difference
   std::set<int> set1 = {1, 2, 3, 4, 5, 6, 7};
   std::set<int> set2 = {3, 4, 5};

   const bool includes_result = std::includes(set1.begin(), set1.end(),
                                      set2.begin(), set2.end());
   
   std::cout << "set2 является подмножеством set1: " 
             << (includes_result ? "да" : "нет") << "\n";
    std::vector<int> diff;
   std::set_difference(set1.begin(), set1.end(),
                      set2.begin(), set2.end(),
                      std::back_inserter(diff));
   
   std::cout << "Разница множеств: ";
   std::copy(diff.begin(), diff.end(), std::ostream_iterator<int>(std::cout, " "));
   std::cout << "\n";
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
