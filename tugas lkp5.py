from csp import *

neighbors = {
    "REKTORAT"  : ["LSI"],
    "LSI"       : ["REKTORAT", "FATETA", "FEM"],
    "FEM": ["LSI", "FEMA"],
    "FATETA"    : ["LSI", "FEMA", "FAHUTAN"],
    "FEMA": ["FEM", "FATETA", "FAHUTAN", "FAPERTA"],
    "FAHUTAN"   : ["FATETA", "FEMA", "FAPERTA", "FMIPA"],
    "FMIPA": ["FAHUTAN", "FAPERTA"],
    "FAPERTA": ["FAHUTAN", "FMIPA", "FEMA"]
}

coloring_problem = MapColoringCSP('RGBY', neighbors)
result = backtracking_search(coloring_problem)
print(result)