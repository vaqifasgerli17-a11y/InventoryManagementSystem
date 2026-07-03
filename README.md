# InventoryManagementSystem

---

## 🇦🇿 Azərbaycan dilində

### Layihə haqqında
Bu, C++ ilə yazılmış konsol tətbiqidir və mağaza/anbar idarəetməsi üçün nəzərdə tutulub. Layihə `header/source/main` strukturunda təşkil olunub və məhsulların əlavə edilməsi, göstərilməsi, axtarılması, satılması, sıralanması və fayla saxlanması funksiyalarını dəstəkləyir.

### Xüsusiyyətlər
- **Məhsul əlavə etmə** — ID, ad, qiymət və stok məlumatları ilə
- **ID əsaslı axtarış** — unikal ID ilə etibarlı axtarış (ad təkrarlana bilər, ID yox)
- **Stokdan satış** — mənfi say və kifayət qədər olmayan stok yoxlaması ilə (`stokdanCixar`)
- **Qiymətə görə sıralama** — `std::sort` və lambda funksiyası ilə
- **Fayla saxlama** — proqram bağlananda məlumat itmir, `mehsullar.txt` faylına avtomatik yazılır/oxunur

### Qovluq strukturu
```
InventoryManagementSystem/
├── include/
│   ├── Mehsul.h
│   └── Magaza.h
├── src/
│   ├── Mehsul.cpp
│   ├── Magaza.cpp
│   └── main.cpp
└── README.md
```

### Compile etmək
```bash
g++ -std=c++17 -Iinclude src/*.cpp -o proqram
./proqram
```

### İstifadə
Proqram işə düşdükdə menyu göstərilir:
1. Mehsul elave et
2. Mehsullari goster
3. ID ile mehsul axtar
4. Mehsul al (ID ile)
5. Qiymete gore sirala
0. Cixis

---

## 🇬🇧 English

### About the Project
This is a console-based C++ application designed for shop/inventory management. The project follows a clean `header/source/main` structure and supports adding, displaying, searching, selling, sorting, and file-persisting products.

### Features
- **Add products** — with ID, name, price, and stock quantity
- **ID-based search** — reliable lookup by unique ID (unlike name, which can be duplicated)
- **Sell from stock** — with proper validation for negative quantities and insufficient stock (`stokdanCixar`)
- **Sort by price** — using `std::sort` with a lambda comparator
- **File persistence** — data is automatically saved to and loaded from `mehsullar.txt`, so nothing is lost when the program closes

### Project Structure
```
InventoryManagementSystem/
├── include/
│   ├── Mehsul.h
│   └── Magaza.h
├── src/
│   ├── Mehsul.cpp
│   ├── Magaza.cpp
│   └── main.cpp
└── README.md
```

### Build Instructions
```bash
g++ -std=c++17 -Iinclude src/*.cpp -o proqram
./proqram
```

### Usage
On launch, the program displays a menu:
1. Add a product
2. Show all products
3. Search product by ID
4. Buy/sell a product (by ID)
5. Sort products by price
0. Exit

---

## 📄 License
This project is free to use for educational purposes.
