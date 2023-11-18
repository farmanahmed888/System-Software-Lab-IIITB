import {Link} from 'react-router-dom';

const Navbar = () => {
  return (
    <div className="navbar">
      <div className="logo">
        <Link to="/">
          <img src={require('./img/logo.jpeg')} alt="logo" width="200" />
        </Link>
      </div>
      <nav>
        <ul id="MenuItems">
          {/*use this id in js*/}
          <li>
            <Link to="/">Home</Link>
          </li>
          <li>
            <Link to="/Products">Products</Link>
          </li>
          <li>
            <Link to="/Account">Account</Link>
          </li>
        </ul>
      </nav>
      <Link to="/Cart">
        <img src={require('./img/cart.png')} alt="cart" width="30px" height="30px" />
      </Link>
    </div>
  );
}

export default Navbar;