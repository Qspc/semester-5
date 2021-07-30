from search import *

jakarta_map = UndirectedGraph(dict(
    sudirman=dict(gbk=30,wtc=30),
    hi=dict(sarinah=15,jpo=70,manggarai=90,gbk=50,wtc=20),
    jpo=dict(sarinah=25,amggarai=40,gatot=55),
    munas=dict(sarinah=15,lapdek=20),
    istiqlal=dict(lapdek=10,gatot=20,sarinah=35),
    gambir=dict(istiqlal=15,gatot=10,sarinah=25)))

jakarta_map.locations = dict(
    sudirman=(40, 10), gbk=(10,20), wtc=(60,20), hi=(50,50),
    manggarai=(120,30), jpo=(100,55), sarinah=(60,80),
    munas=(40,90), lapdek=(50,150), istiqlal=(85,150),
    gambir=(100,100), gatot=(110,120))


jakarta_problem = GraphProblem('sudirman', 'istiqlal', jakarta_map)

print([node.state for node in depth_first_graph_search(jakarta_problem).path()])
print([node.state for node in breadth_first_graph_search(jakarta_problem).path()])

print([node.state for node in best_first_graph_search(jakarta_problem, lambda node: node.path_cost).path()])
print([node.state for node in astar_search (jakarta_problem).path()])