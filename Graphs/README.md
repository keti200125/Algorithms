# Graphs
* [BFS](https://github.com/keti200125/Algorithms/blob/main/Graphs/BFS.cpp)
* [DFS](https://github.com/keti200125/Algorithms/blob/main/Graphs/DFS.cpp)
###
---
###
# Приложения на BFS и DFS

### 1. Обхождане
* Преминаване през върховете и ребрата на граф, маркирайки върховете. Формулира се като задача за ориентирани мултиграфи с възможни примки. Реализира се чрез BFS (Breadth-first search
)-алгоритъм за обхождане в ширина и DFS (Depth-first search)-алгоритъм за обхождане в дълбочина. 
* Сложност на BFS и DFS: Θ(n+m)
### 2. Двуделност/ 2-оцветимост на неориентирани мултиграфи
* граф е двуделен <-> няма нечетни цикли
* задачата може да се реши чрез модификация на BFS
* върховете от единия дял са на четно разстояние от реброто, а върховете на другия са на нечетно разстояние. distance[i] е разстоянието от началния връх до връх i. Ако съществува ребро e=(u,v), такова че distance[u]=distanve[v], то графът не е двуделен. 
* Сложност: Θ(n+m)
### 3. Намиране на най-къс път в нетегловни графи
* решение чрез BFS 
* BFS обхожда по нива, което гарантира, че се посещават всички върхове на текущото ниво преди да се достигне следващото, тоест намира най-къс път от началния връх до търсения.
* Сложност: Θ(n+m)

### 4. Свързаност на графи
* решение чрез модификация на BFS или DFS
* от един стартов връх можем да обходим всички върхове, ако графът е свъзан. В противен случай, ще останат необходени върхове след първото изпълнение на  BFSHelper(DFSHelper).
* можем да намерим и броя на свързаните компоненти, ако преброим колко пъти се извиква помощната функция BFSHelper(DFSHelper) в главаната BFS(DFS). 
* Сложност: Θ(n+m)

### 5. Изследване на цикличност 
* чрез DFS
* ребро назад - ребро, с което достигаме връх, който е посетен
* граф е цикличен <-> DFS открива поне едно ребро назад

### 6. Модификация на DFS намира приложение в решаването и на други задачи:
1. Топологическо сортиране
2. Намиране на силно свързани компоненти - Tarjan

### 
---
### 
# Топологическо сортиране
* **Определение:** Топологическо сортиране на G, или накратко топо-сортиране на G, е всяка биекция
h : V -> {1, . . . , n}, такава че за всяко ребро e=(u,v) е вярно, че h(u) < h(v).

* Съществува топологическо сортиране на G <-> G е даг (ориентиран ацикличен граф).

* Източник(source) е всеки връх в G, чиято полустепен на входа е нула.
Сифон(sink) е всеки връх в G, чиято полустепен на изхода е нула. Във всеки даг има поне един източник и поне един сифон.

* всеки даг има поне един източник и един сифон

* **Определение 2:** Топологическо сортиране на даг G е всяка биекция h : V -> {1, . . . , n}, такава че за всеки връх v, принадлежащ на V: v е източник в G  - {h^(-1) (1), ..., h^(-1)(h(v)-1)} 

## Алгоритъм на Tarjan
* модификация на DFS
* същината на алгоритъма е да се наредят върховете по НАМАЛЯВАЩИ финални стойности 
* най-малката финална стойност задължително е на сифон 




## Алгоритъм на Kahn

*

## Алгоритъм на Kosaraju





