import requests
from bs4 import BeautifulSoup

i = 0

URL = 'https://news.detik.com/indeks'
page = requests.get(URL)

soup = BeautifulSoup(page.content, 'html.parser')
# results = soup.find_all(class_="media__title")

page = soup.find_all(class_="pagination__item")
print(page[len(page)-2].string)
pagination = int(page[len(page)-2].string)

listlink = []

for pg in range(pagination):

    # if i > 3:
    #     break
# print(results)
    
    URL = 'https://news.detik.com/indeks/' + str(pg)
    page = requests.get(URL)

    soup = BeautifulSoup(page.content, 'html.parser')
    results = soup.find_all(class_="media__title")

    for res in results:
        # if i > 3:
        #     break
        link = res.find("a", class_="media__link")['href']
        if 'https' not in link or '/tag/' in link:
            continue
        link += '?single=1'
        listlink.append(link)
        print(link)
        i += 1
        page = requests.get(link)
        isi = ""
        soup = BeautifulSoup(page.content, 'html.parser')

        results = soup.find_all("p")
        for re in results:
            isi += str(re.string)
        # print(results)
        title = str(soup.find(class_="detail__title").string)
        # print(title)

        f = open("scrap\\" + str(i) + ".txt", "w")
        f.write(title + " " + isi)
        f.close()

print(listlink)
f = open("sumber.txt", "w")
f.write("\n".join(listlink) + "\n" + str(i))
f.close()