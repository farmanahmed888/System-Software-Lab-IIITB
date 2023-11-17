const Navbar = () => {
    return ( 
        <div className="navbar">
          <div className="logo">
            <a href="index.html">
              <img src={require('./img/logo.jpeg')} alt="logo" width="200" />
            </a>
          </div>
          <nav>
            <ul id="MenuItems">
              {/*use this id in js*/}
              <li>
                <a href="index.html">Home</a>
              </li>
              <li>
                <a href="Products.html">Products</a>
              </li>
              <li>
                <a href="/">About</a>
              </li>
              <li>
                <a href="/">Contact</a>
              </li>
              <li>
                <a href="account.html">Account</a>
              </li>
            </ul>
          </nav>
          <a href="cart.html">
            <img src={require('./img/cart.png')} alt="cart" width="30px" height="30px" />
          </a>
        </div>
    );
}
 
export default Navbar;