const Cart = () => {
    return (
        <div className="Cart">
            <div className="small container cart-page">
                <table>
                    <tbody>
                        <tr>
                            <th>Product</th>
                            <th>Quantity</th>
                            <th>Subtotal</th>
                        </tr>
                        <tr>
                            <td>
                                <div className="cart-info">
                                    <img src={require("./img/buy-1.jpg")} alt="buy-1" />
                                    <div>
                                        <p>Product</p>
                                        <small>Price: $50.00</small>
                                        <a href="/">Remove</a>
                                    </div>
                                </div>
                            </td>
                            <td>
                                <input type="number" defaultValue={1} />
                            </td>
                            <td>$50.00</td>
                        </tr>
                        <tr>
                            <td>
                                <div className="cart-info">
                                    <img src={require("./img/buy-2.jpg")} alt="buy-2" />
                                    <div>
                                        <p>Product</p>
                                        <small>Price: $60.00</small>
                                        <a href="/">Remove</a>
                                    </div>
                                </div>
                            </td>
                            <td>
                                <input type="number" defaultValue={1} />
                            </td>
                            <td>$60.00</td>
                        </tr>
                        <tr>
                            <td>
                                <div className="cart-info">
                                    <img src={require("./img/buy-3.jpg")} alt="buy-3" />
                                    <div>
                                        <p>Product</p>
                                        <small>Price: $75.00</small>
                                        <a href="/">Remove</a>
                                    </div>
                                </div>
                            </td>
                            <td>
                                <input type="number" defaultValue={1} />
                            </td>
                            <td>$75.00</td>
                        </tr>
                    </tbody>
                </table>
                <div className="total-price">
                    <table>
                        <tbody>
                            <tr>
                                <td>Subtotal</td>
                                <td>$200.00</td>
                            </tr>
                            <tr>
                                <td>Tax</td>
                                <td>$30.00</td>
                            </tr>
                            <tr>
                                <td>Total</td>
                                <td>$230.00</td>
                            </tr>
                        </tbody>
                    </table>
                </div>
            </div>

        </div>
    );
}

export default Cart;