Hi,

Please find below the exercise which you can develop in max 4 hours starting from now. The goal of the assignment is to demonstrate your design and coding skills. You can use your preferred programming language.

Good luck!

***************

1) Streaming Sliding Window volatility

Description:
- We receive a price every minute
- We keep track of prices for 3 days (3600 * 24 * 3 / 60 = 4320 points)
- Every time we receive new price we would like to recalculate volatility for last 3 days (just remove oldest price and add new and adjust volatility)

Implement a class with methods:
- void add_point(float price, int timestamp)
- float get_volatility()

There are at least three ways to solve the problem:
1) recalculate variance by naive re-pass whole data-set
2) split 3 days in sub-periods tree and then union result of sub-periods so solve it in something like O(log N)
3) use smart Math to re-calculate it in O(1) (see references)

You are welcome to select one or implement your own one.

References:
- https://math.stackexchange.com/questions/80195/variance-over-two-periods-with-known-variances
- http://www.taylortree.com/2010/11/running-variance.html
- https://stackoverflow.com/questions/5147378/rolling-variance-algorithm

2) Bookkeeper

Description:
- We want to create an independent component (server) which is responsible for managing exchange data (e.g. market/our own orders and trades). We name this server component the bookkeeper.
- The bookkeeper connects to (at least) 2 exchange data sources, such as the http and websocket api, and combines the orders and trades of these different sources to an internal list of orders and trades. Each data source provide the same information but a data source might be missing information (e.g. a congested websocket line) or provide the data differently (increments vs a list)
- Other components (clients) should be able to subscribe to the bookkeeper in order to receive exchange topics and send/edit/cancel an order to the bookkeeper, which will forward this order to the exchange.
- The bookkeeper should always have a correct and up to date list of orders and trades

Design the bookkeeper server and a client on the class method level.

The client should be able to:
- subscribe for a topic
- process a topic event
- create an order
- edit an order
- cancel an order

Everything should use asynchronous programming approaches. Take into account that an exchange needs ~0.1-0.5sec to round-trip on each request and that sent in-flight orders might not be handled by the exchange.

If you run out of time, try to design this question at the class level instead of the method level.

***************
