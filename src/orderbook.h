#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <order.h>
#include <transaction.h>

#include <functional>
#include <list>
#include <map>
#include <memory>
#include <unordered_map>

class OrderBook {
   public:
    bool receiveOrder(std::shared_ptr<Order> order);

    const std::vector<Transaction>& transactions() const;

   private:
    // unordered map of order pointers for fast UID lookup
    std::unordered_map<std::string, std::shared_ptr<Order>> d_uidMap;

    // groups orders by price (orders with same price go in same group)
    std::map<double, std::list<std::shared_ptr<Order>>> d_sellOrders;
    std::map<double, std::list<std::shared_ptr<Order>>,
             std::greater<double>>
        d_buyOrders;

    void addSellOrder(std::shared_ptr<Order> order);
    void addBuyOrder(std::shared_ptr<Order> order);

    std::vector<Transaction> d_transactions;

    Transaction match(std::shared_ptr<Order> buyOrder,
                      std::shared_ptr<Order> sellOrder);
};

#endif  // ORDERBOOK_H
