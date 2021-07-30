#Tugas 4
# - Indexing dilakukan dengan menggunakan stopwords baku bahasa Inggris seperti yang tersimpan pada file stopwords.txt
# - Pembobotan yang digunakan adalah TF
# - Ukuran kedekatan antar vektor menggunakan metode COSINE SIMILARITY
# - Clustering menggunakan Hierarchical Clustering
# - Ukuran kedekatan antar kelompok menggunakan: (a) single link, dan (b) average link
# - Hasil dievaluasi menggunakan nilai Purity

#Memmasukkan data
data.raw <- read.csv("cluster.csv", header = FALSE)
data.raw <- data.raw[-c(1),]
names(data.raw) <- c("ID", "Class", "Abstract")
data.raw$Class <- as.numeric(as.factor(data.raw$Class))-1

#Merubah Abstract Menjadi Vektor
data.raw$ID <- as.factor(data.raw$ID)
data.raw$Abstract <- as.vector(data.raw$Abstract)

#Masukkan Stopwords
stop_words <- read.delim("stopwords.txt", header = FALSE)
stop_words <- as.vector(stop_words$V1)
stop_words <- tokens(stop_words, what = "word", 
                     remove_numbers = TRUE, remove_punct = TRUE,
                     remove_symbols = TRUE, split_hyphens = TRUE)
stop_words <- stop_words[["text1"]]

#Memisah setiap kata
library(quanteda)
data.pecah <- tokens(data.raw$Abstract, what = "word", 
                     remove_numbers = TRUE, remove_punct = TRUE,
                     remove_symbols = TRUE, split_hyphens = TRUE)

#Merubah setiap kata menjadi huruf kecil
data.pecah <- tokens_tolower(data.pecah)

#Menghilangkan Stopwords
data.bersih <- tokens_select(data.pecah, stop_words, selection = "remove")

#Memberi ID setiap dokuen
names(data.bersih) <- data.raw$ID

#Menghitung TF dan Membentuk TDM
data.dfm <- dfm(data.bersih, tolower = FALSE)
data.matriks <- as.matrix(data.dfm)
View(data.matriks)

#Menghitung Cosine Simmilarity setiap dokumen
cos.sim <- function(ix){
     A = data.matriks[ix[1],]
     B = data.matriks[ix[2],]
     return(sum(A*B)/sqrt(sum(A^2)*sum(B^2)))
}
n <- nrow(data.matriks)
cmb <- expand.grid(i=1:n, j=1:n)
data.sim <- matrix(apply(cmb,1,cos.sim),n,n)

#Menentukan disimmilarity
data.dis <- dist(data.sim)

#Average Linkage
average.linkage <- hclust(data.dis, method = "average", members = NULL)
clustering.al <- cutree(average.linkage, 6)
plot(average.linkage, main = "Average Linkage")
rect.hclust(average.linkage, 6, border = "green")

#Single Linkage
single.linkage <- hclust(data.dis, method = "single", members = NULL)
clustering.sl <- cutree(single.linkage, 6)
plot(single.linkage, main = "Single Linkage")
rect.hclust(single.linkage, 6, border = "green")

#Fungsi Cluster Purity
ClusterPurity <- function(clusters, classes) {
  sum(apply(table(classes, clusters), 2, max)) / length(clusters)
}

#Evaluasi purity average linkage
ClusterPurity(clustering.al, data.raw$Class)

#Evaluasi purity single linkage
ClusterPurity(clustering.sl, data.raw$Class)