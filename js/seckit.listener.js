Drupal.behaviors.seckit = {
  attach: function(context) {
    seckit_listener_hsts(context);
    seckit_listener_csp(context);
    seckit_listener_origin(context);
    (function ($) {
      $('#edit-seckit-ssl-hsts', context).click(function () {
        seckit_listener_hsts(context)
      });
      $('#edit-seckit-xss-csp-checkbox', context).click(function () {
        seckit_listener_csp(context)
      });
      $('#edit-seckit-xss-csp-policy-uri', context).blur(function () {
        seckit_listener_csp(context)
      });
      $('#edit-seckit-csrf-origin', context).click(function () {
        seckit_listener_origin(context)
      });
    })(jQuery);
  }
};

/**
 * Adds/removes attributes for input fields in
 * SSL/TLS fieldset for HTTP Strict Transport Security.
 */
function seckit_listener_hsts(context) {
  (function ($) {
    if ($('#edit-seckit-ssl-hsts').is(':checked')) {
      $('#edit-seckit-ssl-hsts-max-age', context).removeAttr('disabled');
      $('#edit-seckit-ssl-hsts-subdomains', context).removeAttr('disabled');
      $('label[for="edit-seckit-ssl-hsts-max-age"]', context).append('<span title="' + Drupal.t('This field is required.') + '" class="form-required">*</span>');
    }
    else {
      $('#edit-seckit-ssl-hsts-max-age', context).attr('disabled', 'disabled');
      $('#edit-seckit-ssl-hsts-subdomains', context).attr('disabled', 'disabled');
      $('label[for="edit-seckit-ssl-hsts-max-age"] > span', context).remove();
    }
  })(jQuery);
}

/**
 * Adds/removes attributes for input fields in
 * Content Security Policy fieldset.
 */
function seckit_listener_csp(context) {
  (function ($) {
    var checkbox_status = $('#edit-seckit-xss-csp-checkbox').is(':checked');
    var policy_uri_status = $('#edit-seckit-xss-csp-policy-uri').val().length === 0;
    if (checkbox_status) {
      $('#edit-seckit-xss-csp-report-only', context).removeAttr('disabled');
      $('#edit-seckit-xss-csp-policy-uri', context).removeAttr('disabled');
      if (!policy_uri_status) {
        _seckit_csp_add_attributes(context)
      }
      else {
        _seckit_csp_remove_attributes(context);
      }
    }
    else {
      $('#edit-seckit-xss-csp-report-only', context).attr('disabled', 'disabled');
      $('#edit-seckit-xss-csp-policy-uri', context).attr('disabled', 'disabled');
      _seckit_csp_add_attributes(context);
    }
  })(jQuery);
}

/**
 * Removes attributes for CSP input fields.
 */
function _seckit_csp_remove_attributes(context) {
  (function ($) {
    $('#edit-seckit-xss-csp-default-src', context).removeAttr('disabled');
    $('#edit-seckit-xss-csp-script-src', context).removeAttr('disabled');
    $('#edit-seckit-xss-csp-object-src', context).removeAttr('disabled');
    $('#edit-seckit-xss-csp-img-src', context).removeAttr('disabled');
    $('#edit-seckit-xss-csp-media-src', context).removeAttr('disabled');
    $('#edit-seckit-xss-csp-style-src', context).removeAttr('disabled');
    $('#edit-seckit-xss-csp-frame-src', context).removeAttr('disabled');
    $('#edit-seckit-xss-csp-font-src', context).removeAttr('disabled');
    $('#edit-seckit-xss-csp-xhr-src', context).removeAttr('disabled');
    $('#edit-seckit-xss-csp-frame-ancestors', context).removeAttr('disabled');
    $('#edit-seckit-xss-csp-report-uri', context).removeAttr('disabled');
    $('#edit-seckit-xss-csp-options', context).removeAttr('disabled');
  })(jQuery);
}

/**
 * Adds attributes for CSP input fields.
 */
function _seckit_csp_add_attributes(context) {
  (function ($) {
    $('#edit-seckit-xss-csp-default-src', context).attr('disabled', 'disabled');
    $('#edit-seckit-xss-csp-script-src', context).attr('disabled', 'disabled');
    $('#edit-seckit-xss-csp-object-src', context).attr('disabled', 'disabled');
    $('#edit-seckit-xss-csp-img-src', context).attr('disabled', 'disabled');
    $('#edit-seckit-xss-csp-media-src', context).attr('disabled', 'disabled');
    $('#edit-seckit-xss-csp-style-src', context).attr('disabled', 'disabled');
    $('#edit-seckit-xss-csp-frame-src', context).attr('disabled', 'disabled');
    $('#edit-seckit-xss-csp-font-src', context).attr('disabled', 'disabled');
    $('#edit-seckit-xss-csp-xhr-src', context).attr('disabled', 'disabled');
    $('#edit-seckit-xss-csp-frame-ancestors', context).attr('disabled', 'disabled');
    $('#edit-seckit-xss-csp-report-uri', context).attr('disabled', 'disabled');
    $('#edit-seckit-xss-csp-options', context).attr('disabled', 'disabled');
  })(jQuery);
}

/**
 * Adds/removes attributes for input fields in
 * Cross-site Request Forgery fieldset for HTTP Origin.
 */
function seckit_listener_origin(context) {
  (function ($) {
    if ($('#edit-seckit-csrf-origin').is(':checked')) {
      $('#edit-seckit-csrf-origin-whitelist', context).removeAttr('disabled');
    }
    else {
      $('#edit-seckit-csrf-origin-whitelist', context).attr('disabled', 'disabled');
    }
  })(jQuery);
}
