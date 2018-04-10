fun main(args: Array<String>) {
    var (N, Y) = readLine()!!.split(" ").map{it.toInt()}
    val x = Y/10000
    val y = Y/5000
    val z = Y/1000
    for (i in 0..x) {
        for (j in 0..y) {
            for (k in 0..z) {
                if ((i+j+k==N)&&(i*10000+j*5000+k*1000==Y)) {
                    println("$i $j $k")
                    return
                }
                if ((i+j+k>N)||(i*10000+j*5000+k*1000>Y)) break
            }
        }
    }
    println("-1 -1 -1")
}
