fun main(args: Array<String>) {
    var N = readLine()!!
    var flag = false
    for (i in 0..1) {
        flag = flag or (N[i] == N[i + 1] && N[i + 1] == N[i + 2])
    }
    println(if (flag) "Yes" else "No")
}
