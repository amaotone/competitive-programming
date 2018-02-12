fun main(args: Array<String>) {
    val Q = readLine()!!.toInt()
    var query = Array(Q, {arrayOf(0, 0)})
    var vmax = 0
    for (i in 0..Q-1) {
        var (low, high) = readLine()!!.split(" ").map{it.toInt()}
        if (high>vmax) vmax = high
        query[i][0] = low
        query[i][1] = high
    }
    // generate prime numbers
    var ref = Array(vmax+1, {true})
    ref[0] = false
    ref[1] = false
    for (i in 2..vmax/2) {
        if (ref[i]==false) continue
        for (j in 2..(vmax)/i) {
            ref[i*j] = false
        }
    }
    // check
    var ans = Array(vmax+1, {0})
    for (i in 1..vmax) {
        if (ref[i]&&ref[(i+1)/2]) ans[i] = ans[i-1]+1
        else ans[i] = ans[i-1]
    }
    query.forEach {
        println(ans[it[1]]-ans[it[0]-1])
    }
}
