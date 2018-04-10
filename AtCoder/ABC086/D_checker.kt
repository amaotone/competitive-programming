inline fun <reified T> matrix2d(height: Int, width: Int, initialize: () -> T) =
        Array(height) {Array(width) {initialize()}}

fun getLect(k: Int, v: Int): Array<Pair<Int, Int>> {
    if (v>k) return arrayOf(Pair(0, v-k), Pair(v, 2*k))  // はみ出す
    return arrayOf(Pair(v, v+k))
} 

fun main(args: Array<String>) {
    val (n, k) = readLine()!!.split(" ").map{it.toInt()}
    val k2 = k*2
    var x: Int
    var y: Int
    var tile = matrix2d(k2+1, k2+1) {0}
    for (z in 1..n) {
        val (xc, yc, c) = readLine()!!.split(" ")
        x = xc.toInt() % k2
        y = yc.toInt() % k2
        if (c=="W") {
            x += k
            x %= k2
        }
        for (i in listOf(0, k)) {
            for ((xmin, xmax) in getLect(k, (x+i)%k2)) {
                for ((ymin, ymax) in getLect(k, (y+i)%k2)) {
                    tile[xmin][ymin] += 1
                    tile[xmax][ymin] -= 1
                    tile[xmin][ymax] -= 1
                    tile[xmax][ymax] += 1
                }
            }
        }
    } 

    for (i in 0..k2) {
        for (j in 1..k2) {
            tile[i][j] += tile[i][j-1]
        }
    }
    for (i in 1..k2) {
        for (j in 0..k2) {
            tile[i][j] += tile[i-1][j]
        }
    }
    var ans = 0
    for (i in 0..k2) {
        for (j in 0..k2) {
            if (tile[i][j]>ans) ans = tile[i][j]
        }
    }
    // tile.forEach {
    //     println(it.toList())
    // }
    println(ans)
}