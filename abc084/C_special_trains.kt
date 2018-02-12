fun main(args: Array<String>) {
    val N = readLine()!!.toInt()
    var C = IntArray(N-1, {0})
    var S = IntArray(N-1, {0})
    var F = IntArray(N-1, {0})
    for (i in 0..N-2) {
        var (c, s, f) = readLine()!!.split(" ").map{it.toInt()}
        C[i] = c
        S[i] = s
        F[i] = f
    }
    var ans: Int
    for (i in 0..N-1) {
        ans = 0
        for (j in i..N-2) {
            if (ans < S[j]) ans = S[j]
            else ans = ((ans-S[j]-1)/F[j]+1)*F[j] + S[j]
            ans += C[j]
        }
        println(ans)
    }
}
