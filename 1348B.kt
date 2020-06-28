fun main() {
    val t = readLine()!!.toInt()
    for (x in 0 until t) {
        val meta = readLine()!!.split(" ", limit = 2)
        val n = meta[0].toInt()
        val k = meta[1].toInt()

        val input = readLine()!!.split(" ", limit = n)
        val mutable = MutableList(n) { index -> input[index].toInt() }
        solve(n, k, mutable)
    }

}

fun seq(n: Int) = List(n) { index -> index }

fun solve(n: Int, k: Int, output: MutableList<Int>) {
    if (n > k) {
        val table = output.distinct().toMutableList()
        if (table.size > k) println("-1").also { return }
        if (table.size < k) table.addAll(
            index = 0,
            elements = List(k - table.size) { table[0] })

        var i = -1
        while (++i < output.size) {
            if (table[i % table.size] != output[i]) output.add(index = i, element = table[i % table.size])
        }
    }

    println(output.size)
    output.forEach { num: Int -> print("$num ") }.also { println() }

    // 4 3
    // 2 2 3 4
}
